#!/usr/bin/env python3
"""
README.md updater for LeetCode progress tracking
This script scans your solutions directory and updates the README.md file
"""

import os
import re
from datetime import datetime
from pathlib import Path

class LeetCodeReadmeUpdater:
    def __init__(self, repo_path="."):
        self.repo_path = Path(repo_path)
        self.solutions_dir = self.repo_path / "solutions"
        self.readme_path = self.repo_path / "README.md"
        
    def scan_solutions(self):
        """Scan solutions directory for problem files"""
        if not self.solutions_dir.exists():
            return []
        
        solutions = []
        for file_path in self.solutions_dir.rglob("*.py"):  # Adjust extension as needed
            # Extract problem info from filename
            filename = file_path.stem
            # Example: "1_two_sum.py" -> problem_num=1, title="Two Sum"
            match = re.match(r'(\d+)_(.+)', filename)
            if match:
                problem_num = int(match.group(1))
                title = match.group(2).replace('_', ' ').title()
                solutions.appen