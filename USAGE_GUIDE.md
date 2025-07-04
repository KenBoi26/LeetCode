# LeetCode README Updater - Usage Guide

## Overview
This enhanced script automatically organizes your LeetCode solutions by submission date and creates a comprehensive progress tracker.

## Features

### 📅 Day-based Organization
- Solutions are grouped by the day they were submitted/committed
- Each day shows as "DAY X - Date" with formatted date
- Problems within each day are sorted by submission time

### 📊 Progress Tracking
- **Stats Section**: Badge-style counters for Easy/Medium/Hard problems
- **Difficulty Breakdown**: Detailed count per difficulty level
- **Daily Summary**: Quick overview of problems solved each day
- **Recent Submissions**: Last 5 problems solved with timestamps

### 🔄 How It Works

1. **Date Detection**: Uses file modification timestamps to determine submission dates
2. **Sorting**: Problems are sorted by submission date/time, then by problem number
3. **Grouping**: Solutions are grouped by day for easy navigation
4. **Auto-Update**: All sections update automatically when you run the script

## Running the Script

```bash
python update_readme.py
```

## For Future Submissions

When you solve new problems:
1. The script will automatically detect the new solution files
2. They will be added to the appropriate day based on when the files were modified
3. If you solve problems on a new day, a new "DAY X" section will be created
4. Recent submissions and all other sections will update automatically

## File Structure Expected

```
LeetCode/
├── update_readme.py
├── README.md
├── 1-two-sum/
│   ├── two-sum.cpp
│   └── README.md
├── 20-valid-parentheses/
│   ├── valid-parentheses.cpp
│   └── README.md
└── ...
```

## Customization

You can modify the script to:
- Change the number of recent submissions shown (default: 5)
- Adjust date formatting
- Add more file extensions for solution files
- Customize the markdown output format

## Tips

- Run the script after each coding session to keep your README updated
- The script preserves all existing content outside the marked sections
- File modification times are used for dating, so avoid unnecessary edits to solution files
- The script automatically handles different time zones and date formats
