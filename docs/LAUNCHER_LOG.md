# Launcher Log

Log follows the launcher's shared heading, uppercase group labels, native
dropdowns, toggle switch and content width. Session and stream selectors sit
above the log with Open file, Open folder and Follow controls. The read-only
log stays in Consolas, independent of the launcher font. Empty or missing files
have an inline empty state; an existing empty file waits for its writer.

Reads remain bounded to the latest 128 KiB and permit the game to keep writing.
Follow moves only vertically to the latest line. Appends preserve the horizontal
position; with Follow off, both offsets are preserved. Switching source resets
the view. The horizontal scrollbar track is not reversed; the vertical track
retains its existing downwards direction. The scrollbar corner follows the dark
launcher background.

Run the WPF interaction diagnostic with an isolated data home:

```powershell
Outbreak.Launcher.exe --data-home <isolated-folder> --test-logs-ui <output-folder>
```

The Release publish passed 20 checks covering actual thumb dragging in both
directions, vertical scrolling, following and paused appends, selectable text,
stream changes, queued refreshes, empty/missing/resumed files and minimum window
size, including the full Stream dropdown border fitting within its column.
The diagnostic creates synthetic session logs only in the isolated home
and records screenshots and `result.json` in the output folder.
