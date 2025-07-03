#!/usr/bin/env python3
"""
README.md updater for LeetCode progress tracking.

This script scans the repository for LeetCode solution directories,
gathers metadata about each solution, and updates the main README.md
with the latest progress stats and a table of solved problems.
"""

import os
import re
from pathlib import Path
from datetime import datetime
from collections import defaultdict

class LeetCodeReadmeUpdater:
    """
    A class to scan LeetCode solutions and update the README.md.
    """
    def __init__(self, repo_path="."):
        """
        Initializes the updater with the repository path.
        
        Args:
            repo_path (str): The root path of the repository.
        """
        self.repo_path = Path(repo_path).resolve()
        self.readme_path = self.repo_path / "README.md"
        # Common solution file names used by tools like leetsync
        self.solution_files = ["solution.py", "solution.js", "solution.java", "solution.cpp", "solution.go", "solution.ts"]
        print(f"Initializing updater for repository at: {self.repo_path}")

    def scan_solutions(self):
        """
        Scans the repository for LeetCode solution directories.
        
        A directory is considered a solution if it starts with a number
        and a hyphen, e.g., "1-two-sum".
        
        Returns:
            list: A sorted list of dictionaries, each representing a solved problem.
        """
        print("Scanning for solution directories...")
        solutions = []
        
        for item in self.repo_path.iterdir():
            if not item.is_dir():
                continue

            # Match directories like "1-two-sum" or "1435-xor-queries-of-a-subarray"
            match = re.match(r'(\d+)-(.+)', item.name)
            if not match:
                continue
            
            problem_num = int(match.group(1))
            problem_slug = match.group(2)
            title = problem_slug.replace('-', ' ').title()
            
            solution_path = None
            for filename in self.solution_files:
                if (item / filename).exists():
                    solution_path = item / filename
                    break
            
            if not solution_path:
                print(f"Warning: No solution file found in {item.name}")
                continue

            difficulty = self._get_difficulty(item)
            
            solutions.append({
                "number": problem_num,
                "title": title,
                "slug": problem_slug,
                "path": solution_path.relative_to(self.repo_path).as_posix(),
                "difficulty": difficulty,
            })
        
        # Sort solutions by problem number
        solutions.sort(key=lambda s: s["number"])
        print(f"Found {len(solutions)} solved problems.")
        return solutions

    def _get_difficulty(self, problem_dir: Path):
        """
        Extracts the problem difficulty from the README.md inside a problem's folder.
        
        Args:
            problem_dir (Path): The path to the problem's directory.
            
        Returns:
            str: The difficulty ("Easy", "Medium", "Hard") or "Unknown".
        """
        problem_readme = problem_dir / "README.md"
        if not problem_readme.exists():
            return "Unknown"
            
        content = problem_readme.read_text(encoding="utf-8")
        # Look for "Difficulty: Easy" or similar patterns
        match = re.search(r'Difficulty:\s*(Easy|Medium|Hard)', content, re.IGNORECASE)
        if match:
            return match.group(1).capitalize()
            
        return "Unknown"

    def update_readme(self, solutions):
        """
        Updates the main README.md file with the new stats and problem table.
        
        Args:
            solutions (list): The list of solved problems from scan_solutions.
        """
        if not self.readme_path.exists():
            print(f"Error: README.md not found at {self.readme_path}")
            return

        print("Generating new README content...")
        stats_content = self._generate_stats(solutions)
        table_content = self._generate_table(solutions)

        readme_content = self.readme_path.read_text(encoding="utf-8")

        # Replace stats section
        readme_content = re.sub(
            r'<!-- LEETCODE_STATS_START -->(.|\n)*?<!-- LEETCODE_STATS_END -->',
            f'<!-- LEETCODE_STATS_START -->\n{stats_content}\n<!-- LEETCODE_STATS_END -->',
            readme_content
        )

        # Replace table section
        readme_content = re.sub(
            r'<!-- LEETCODE_TABLE_START -->(.|\n)*?<!-- LEETCODE_TABLE_END -->',
            f'<!-- LEETCODE_TABLE_START -->\n{table_content}\n<!-- LEETCODE_TABLE_END -->',
            readme_content
        )
        
        self.readme_path.write_text(readme_content, encoding="utf-8")
        print("✅ README.md has been successfully updated!")

    def _generate_stats(self, solutions):
        """
        Generates the markdown for the statistics badges.
        
        Args:
            solutions (list): The list of solved problems.
            
        Returns:
            str: Markdown content for the stats section.
        """
        counts = defaultdict(int)
        for s in solutions:
            counts[s["difficulty"]] += 1
        
        total = len(solutions)
        easy = counts["Easy"]
        medium = counts["Medium"]
        hard = counts["Hard"]

        stats_md = (
            f"![Easy](https://img.shields.io/badge/Easy-{easy}-green?style=for-the-badge)\n"
            f"![Medium](https://img.shields.io/badge/Medium-{medium}-orange?style=for-the-badge)\n"
            f"![Hard](https://img.shields.io/badge/Hard-{hard}-red?style=for-the-badge)\n\n"
            f"**Total Solved: {total}**"
        )
        return stats_md

    def _generate_table(self, solutions):
        """
        Generates the markdown table of solved problems.
        
        Args:
            solutions (list): The list of solved problems.
            
        Returns:
            str: Markdown content for the problems table.
        """
        if not solutions:
            return "| # | Title | Solution | Difficulty |\n|---|-------|----------|------------|\n| | *No problems synced yet. Start solving on LeetCode!* | | |"

        table_header = "| # | Title | Solution | Difficulty |\n|---|-------|----------|------------|"
        table_rows = []
        for s in solutions:
            leetcode_url = f"https://leetcode.com/problems/{s['slug']}"
            title_link = f"[{s['title']}]({leetcode_url})"
            solution_link = f"[{Path(s['path']).name}]({s['path']})"
            difficulty_badge = f"`{s['difficulty']}`"
            
            row = f"| {s['number']} | {title_link} | {solution_link} | {difficulty_badge} |"
            table_rows.append(row)
            
        return f"{table_header}\n" + "\n".join(table_rows)


if __name__ == "__main__":
    updater = LeetCodeReadmeUpdater()
    solved_problems = updater.scan_solutions()
    updater.update_readme(solved_problems)
