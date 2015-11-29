{
  "variables": {
    "dll_files": ["WinSparkle.dll"],
    "include_dirs": []
  },
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "nodesparkle.cc", "winsparkle.h", "winsparkle-version.h" ]
    }
  ]
}