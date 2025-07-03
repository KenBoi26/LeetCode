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
        # Define common code file extensions to look for
        self.code_extensions = [".py", ".js", ".java", ".cpp", ".go", ".ts", ".cs"] # Added .cs for C#
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
            # Iterate through all files in the problem directory
            for file_in_dir in item.iterdir():
                if file_in_dir.is_file() and file_in_dir.suffix in self.code_extensions:
                    solution_path = file_in_dir
                    break # Found a solution file, no need to check other files
            
            if not solution_path:
                print(f"Warning: No solution file with a recognized code extension found in {item.name}")
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
        difficulty_breakdown_content = self._generate_difficulty_breakdown(solutions)
        table_content = self._generate_table(solutions)

        readme_content = self.readme_path.read_text(encoding="utf-8")

        # Replace stats section (using LEETCODE_STATS_START/END, which matches your README)
        readme_content = re.sub(
            r'<!-- LEETCODE_STATS_START -->(.|\n)*?<!-- LEETCODE_STATS_END -->',
            f'<!-- LEETCODE_STATS_START -->\n{stats_content}\n<!-- LEETCODE_STATS_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
        )

        # Replace difficulty breakdown section
        readme_content = re.sub(
            r'<!-- DIFFICULTY_BREAKDOWN_START -->(.|\n)*?<!-- DIFFICULTY_BREAKDOWN_END -->',
            f'<!-- DIFFICULTY_BREAKDOWN_START -->\n{difficulty_breakdown_content}\n<!-- DIFFICULTY_BREAKDOWN_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
        )

        # Replace table section (UPDATED to use SOLUTIONS_TABLE_START/END)
        readme_content = re.sub(
            r'<!-- SOLUTIONS_TABLE_START -->(.|\n)*?<!-- SOLUTIONS_TABLE_END -->',
            f'<!-- SOLUTIONS_TABLE_START -->\n{table_content}\n<!-- SOLUTIONS_TABLE_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
        )
        
        self.readme_path.write_text(readme_content, encoding="utf-8")
        print("✅ README.md has been successfully updated!")

    def _generate_circular_progress_svg(self, count, total_solved, label, color):
        """
        Generates an SVG for a circular progress bar.
        """
        if total_solved == 0:
            percentage = 0
        else:
            percentage = (count / total_solved) * 100

        # SVG dimensions and circle properties
        radius = 15.9155
        circumference = 2 * 3.14159 * radius # Using pi approx

        # Stroke-dasharray for progress: "percentage, 100"
        # The '100' here refers to 100% of the circumference
        stroke_dasharray = f"{percentage}, 100"

        svg_template = f"""
<div style="display: inline-block; text-align: center; margin: 10px;">
    <svg width="100" height="100" viewBox="0 0 36 36" style="display: block; margin: 0 auto;">
        <path d="M18 2.0845 a 15.9155 15.9155 0 0 1 0 31.831 a 15.9155 15.9155 0 0 1 0 -31.831"
              fill="none" stroke="#e9ecef" stroke-width="3.8" />
        <path d="M18 2.0845 a 15.9155 15.9155 0 0 1 0 31.831 a 15.9155 15.9155 0 0 1 0 -31.831"
              fill="none" stroke="{color}" stroke-width="2.8"
              stroke-dasharray="{stroke_dasharray}"
              stroke-linecap="round"
              transform="rotate(-90 18 18)" />
        <text x="18" y="20.35" text-anchor="middle" font-size="0.6em" fill="#333" font-family="sans-serif">{count}</text>
    </svg>
    <p style="margin-top: 5px; font-size: 0.9em; color: #555; font-family: sans-serif;">{label}</p>
</div>
"""
        return svg_template.strip()

    def _generate_stats(self, solutions):
        """
        Generates the markdown for the statistics (now circular progress SVGs).
        
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
        unknown = counts["Unknown"]

        # Generate individual circular progress SVGs
        easy_svg = self._generate_circular_progress_svg(easy, total, "Easy", "#28a745")
        medium_svg = self._generate_circular_progress_svg(medium, total, "Medium", "#ffc107")
        hard_svg = self._generate_circular_progress_svg(hard, total, "Hard", "#dc3545")

        stats_md = f"""
<div style="display: flex; justify-content: center; align-items: center; flex-wrap: wrap;">
    {easy_svg}
    {medium_svg}
    {hard_svg}
</div>

**Total Solved: {total}**
"""
        if unknown > 0:
            stats_md += f"\n*Note: {unknown} problems have 'Unknown' difficulty.*"
        
        return stats_md

    def _generate_difficulty_breakdown(self, solutions):
        """
        Generates the markdown for the difficulty breakdown section.
        
        Args:
            solutions (list): The list of solved problems.
            
        Returns:
            str: Markdown content for the difficulty breakdown.
        """
        counts = defaultdict(int)
        for s in solutions:
            counts[s["difficulty"]] += 1
        
        easy_solved = counts["Easy"]
        medium_solved = counts["Medium"]
        hard_solved = counts["Hard"]
        unknown_solved = counts["Unknown"]
        
        breakdown_lines = []
        breakdown_lines.append(f"- **Easy**: {easy_solved}/{easy_solved} problems solved")
        breakdown_lines.append(f"- **Medium**: {medium_solved}/{medium_solved} problems solved")
        breakdown_lines.append(f"- **Hard**: {hard_solved}/{hard_solved} problems solved")
        
        if unknown_solved > 0:
            breakdown_lines.append(f"- **Unknown**: {unknown_solved}/{unknown_solved} problems solved")

        return "\n".join(breakdown_lines)

    def _generate_table(self, solutions):
        """
        Generates the markdown table of solved problems,
        matching the user's desired column order and adding LeetCode links.
        
        Args:
            solutions (list): The list of solved problems.
            
        Returns:
            str: Markdown content for the problems table.
        """
        if not solutions:
            # Updated default table to match user's header structure
            return "| # | Title | Difficulty | Solution | LeetCode Link |\n|---|-------|------------|----------|---------------|\n| - | No solutions yet | - | - | - |"

        # Updated table header to match user's README.md
        table_header = "| # | Title | Difficulty | Solution | LeetCode Link |\n|---|-------|------------|----------|---------------|"
        table_rows = []
        for s in solutions:
            leetcode_url = f"https://leetcode.com/problems/{s['slug']}/" # Ensure trailing slash for consistency
            
            # Title linked to LeetCode problem
            title_link = f"[{s['title']}]({leetcode_url})"
            
            # Link to the local solution file
            solution_link = f"[{Path(s['path']).name}]({s['path']})"
            
            difficulty_badge = f"`{s['difficulty']}`"
            
            # Construct the row in the order: # | Title | Difficulty | Solution | LeetCode Link
            # The LeetCode Link column will explicitly show "[Link]"
            row = f"| {s['number']} | {title_link} | {difficulty_badge} | {solution_link} | [Link]({leetcode_url}) |"
            table_rows.append(row)
            
        return f"{table_header}\n" + "\n".join(table_rows)


if __name__ == "__main__":
    # You can specify the path to your LeetCode repository here if it's not the current directory
    # For example: updater = LeetCodeReadmeUpdater(repo_path="D:/1. STUDIES/3. CODING/LeetCode/LeetCode")
    updater = LeetCodeReadmeUpdater()
    solved_problems = updater.scan_solutions()
    updater.update_readme(solved_problems)
