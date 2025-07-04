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
from datetime import datetime, date
from collections import defaultdict, OrderedDict

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
            submission_date = self._get_submission_date(solution_path)
            
            solutions.append({
                "number": problem_num,
                "title": title,
                "slug": problem_slug,
                "path": solution_path.relative_to(self.repo_path).as_posix(),
                "difficulty": difficulty,
                "submission_date": submission_date,
                "submission_datetime": solution_path.stat().st_mtime,
            })
        
        # Sort solutions by submission date and time, then by problem number
        solutions.sort(key=lambda s: (s["submission_datetime"], s["number"]))
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

    def _get_submission_date(self, solution_file: Path):
        """
        Gets the submission date based on the file's modification time.
        
        Args:
            solution_file (Path): The path to the solution file.
            
        Returns:
            str: The submission date in YYYY-MM-DD format.
        """
        modification_time = solution_file.stat().st_mtime
        submission_date = datetime.fromtimestamp(modification_time).date()
        return submission_date.strftime("%Y-%m-%d")

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
        daily_summary_content = self._generate_daily_summary(solutions)
        recent_submissions_content = self._generate_recent_submissions(solutions)
        table_content = self._generate_table(solutions)
        recent_submissions_content = self._generate_recent_submissions(solutions)  # NEW: Generate recent submissions

        readme_content = self.readme_path.read_text(encoding="utf-8")

        # Replace stats section (using LEETCODE_STATS_START/END, which matches your README)
        readme_content = re.sub(
            r'<!-- LEETCODE_STATS_START -->(.|\n)*?<!-- LEETCODE_STATS_END -->',
            f'<!-- LEETCODE_STATS_START -->\n{stats_content}\n<!-- LEETCODE_STATS_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
        )

        # Replace difficulty breakdown section (NEW)
        readme_content = re.sub(
            r'<!-- DIFFICULTY_BREAKDOWN_START -->(.|\n)*?<!-- DIFFICULTY_BREAKDOWN_END -->',
            f'<!-- DIFFICULTY_BREAKDOWN_START -->\n{difficulty_breakdown_content}\n<!-- DIFFICULTY_BREAKDOWN_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
        )

        # Replace daily summary section (NEW)
        readme_content = re.sub(
            r'<!-- DAILY_SUMMARY_START -->(.|\n)*?<!-- DAILY_SUMMARY_END -->',
            f'<!-- DAILY_SUMMARY_START -->\n{daily_summary_content}\n<!-- DAILY_SUMMARY_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
        )

        # Replace recent submissions section
        readme_content = re.sub(
            r'<!-- RECENT_SUBMISSIONS_START -->(.|\n)*?<!-- RECENT_SUBMISSIONS_END -->',
            f'<!-- RECENT_SUBMISSIONS_START -->\n{recent_submissions_content}\n<!-- RECENT_SUBMISSIONS_END -->',
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
        
        # Replace recent submissions section (NEW)
        readme_content = re.sub(
            r'<!-- RECENT_SUBMISSIONS_START -->(.|\n)*?<!-- RECENT_SUBMISSIONS_END -->',
            f'<!-- RECENT_SUBMISSIONS_START -->\n{recent_submissions_content}\n<!-- RECENT_SUBMISSIONS_END -->',
            readme_content,
            flags=re.DOTALL # Ensure . matches newlines
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
        unknown = counts["Unknown"] # Include unknown difficulty in stats

        stats_md = (
            f"![Easy](https://img.shields.io/badge/Easy-{easy}-green?style=for-the-badge)\n"
            f"![Medium](https://img.shields.io/badge/Medium-{medium}-orange?style=for-the-badge)\n"
            f"![Hard](https://img.shields.io/badge/Hard-{hard}-red?style=for-the-badge)\n"
        )
        if unknown > 0: # Only add unknown if there are any
            stats_md += f"![Unknown](https://img.shields.io/badge/Unknown-{unknown}-lightgrey?style=for-the-badge)\n"
        
        stats_md += f"\n**Total Solved: {total}**"
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
        
        # Assuming total problems for each difficulty are not tracked by this script,
        # so it will show solved/solved. If you have total problem counts, you'd
        # need to pass them or fetch them.
        easy_solved = counts["Easy"]
        medium_solved = counts["Medium"]
        hard_solved = counts["Hard"]
        
        # For now, we'll assume total is same as solved for breakdown,
        # or you can hardcode total if you know them.
        # If you want to track total problems for each difficulty,
        # you'd need to extend the script to read that data.
        
        breakdown_md = (
            f"- **Easy**: {easy_solved}/{easy_solved} problems solved\n"
            f"- **Medium**: {medium_solved}/{medium_solved} problems solved\n"
            f"- **Hard**: {hard_solved}/{hard_solved} problems solved"
        )
        # Add unknown if present
        if counts["Unknown"] > 0:
            unknown_solved = counts["Unknown"]
            breakdown_md += f"\n- **Unknown**: {unknown_solved}/{unknown_solved} problems solved"

        return breakdown_md

    def _generate_table(self, solutions):
        """
        Generates the markdown table of solved problems grouped by submission day,
        with each day showing as "DAY X" with the problems submitted that day.
        
        Args:
            solutions (list): The list of solved problems sorted by submission date.
            
        Returns:
            str: Markdown content for the problems table organized by days.
        """
        if not solutions:
            return "| # | Title | Difficulty | Solution | LeetCode Link |\n|---|-------|------------|----------|---------------|\n| - | No solutions yet | - | - | - |"

        # Group solutions by submission date
        solutions_by_date = OrderedDict()
        for solution in solutions:
            sub_date = solution["submission_date"]
            if sub_date not in solutions_by_date:
                solutions_by_date[sub_date] = []
            solutions_by_date[sub_date].append(solution)

        # Generate the table content
        table_content = []
        day_counter = 1
        
        for date_str, date_solutions in solutions_by_date.items():
            # Convert date string to a more readable format
            try:
                date_obj = datetime.strptime(date_str, "%Y-%m-%d").date()
                formatted_date = date_obj.strftime("%B %d, %Y")  # e.g., "July 03, 2025"
            except:
                formatted_date = date_str
                
            # Add day header
            table_content.append(f"\n### 📅 DAY {day_counter} - {formatted_date}")
            table_content.append(f"*{len(date_solutions)} problem(s) solved*\n")
            
            # Add table header for this day
            table_header = "| # | Title | Difficulty | Solution | LeetCode Link |\n|---|-------|------------|----------|---------------|"
            table_content.append(table_header)
            
            # Add rows for this day's solutions
            for solution in date_solutions:
                leetcode_url = f"https://leetcode.com/problems/{solution['slug']}/"
                title_link = f"[{solution['title']}]({leetcode_url})"
                solution_link = f"[{Path(solution['path']).name}]({solution['path']})"
                difficulty_badge = f"`{solution['difficulty']}`"
                
                row = f"| {solution['number']} | {title_link} | {difficulty_badge} | {solution_link} | [Link]({leetcode_url}) |"
                table_content.append(row)
            
            day_counter += 1
        
        return "\n".join(table_content)

    def _generate_daily_summary(self, solutions):
        """
        Generates a summary of problems solved each day.
        
        Args:
            solutions (list): The list of solved problems sorted by submission date.
            
        Returns:
            str: Markdown content for the daily summary.
        """
        if not solutions:
            return "*No solutions yet. Start solving problems to see your daily progress!*"

        # Group solutions by submission date
        solutions_by_date = OrderedDict()
        for solution in solutions:
            sub_date = solution["submission_date"]
            if sub_date not in solutions_by_date:
                solutions_by_date[sub_date] = []
            solutions_by_date[sub_date].append(solution)

        summary_lines = []
        day_counter = 1
        
        for date_str, date_solutions in solutions_by_date.items():
            try:
                date_obj = datetime.strptime(date_str, "%Y-%m-%d").date()
                formatted_date = date_obj.strftime("%B %d, %Y")
            except:
                formatted_date = date_str
                
            # Count by difficulty for this day
            easy_count = sum(1 for s in date_solutions if s["difficulty"] == "Easy")
            medium_count = sum(1 for s in date_solutions if s["difficulty"] == "Medium")
            hard_count = sum(1 for s in date_solutions if s["difficulty"] == "Hard")
            
            difficulty_breakdown = []
            if easy_count > 0:
                difficulty_breakdown.append(f"{easy_count} Easy")
            if medium_count > 0:
                difficulty_breakdown.append(f"{medium_count} Medium")
            if hard_count > 0:
                difficulty_breakdown.append(f"{hard_count} Hard")
            
            breakdown_str = ", ".join(difficulty_breakdown) if difficulty_breakdown else "No problems"
            
            summary_lines.append(f"- **DAY {day_counter}** ({formatted_date}): {len(date_solutions)} problem(s) - {breakdown_str}")
            day_counter += 1
        
        return "\n".join(summary_lines)

    def _generate_recent_submissions(self, solutions, limit=5):
        """
        Generates a list of recent submissions (last N problems solved).
        
        Args:
            solutions (list): The list of solved problems sorted by submission date.
            limit (int): Maximum number of recent submissions to show.
            
        Returns:
            str: Markdown content for recent submissions.
        """
        if not solutions:
            return "*No recent submissions yet. Start solving problems to see your progress here!*"

        # Get the most recent submissions (already sorted by date/time)
        recent = solutions[-limit:] if len(solutions) > limit else solutions
        recent.reverse()  # Show most recent first
        
        recent_lines = []
        for solution in recent:
            try:
                # Get the submission datetime for display
                submission_datetime = datetime.fromtimestamp(solution["submission_datetime"])
                time_str = submission_datetime.strftime("%B %d, %Y at %I:%M %p")
            except:
                time_str = solution["submission_date"]
            
            leetcode_url = f"https://leetcode.com/problems/{solution['slug']}/"
            solution_link = f"[{Path(solution['path']).name}]({solution['path']})"
            difficulty_badge = f"`{solution['difficulty']}`"
            
            recent_lines.append(
                f"- **#{solution['number']}** [{solution['title']}]({leetcode_url}) "
                f"({difficulty_badge}) - {time_str} | [Solution]({solution['path']})"
            )
        
        return "\n".join(recent_lines)


if __name__ == "__main__":
    # You can specify the path to your LeetCode repository here if it's not the current directory
    # For example: updater = LeetCodeReadmeUpdater(repo_path="D:/1. STUDIES/3. CODING/LeetCode/LeetCode")
    updater = LeetCodeReadmeUpdater()
    solved_problems = updater.scan_solutions()
    updater.update_readme(solved_problems)
