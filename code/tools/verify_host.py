from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[1]
targets = sorted(root.glob("labs/*/main.c")) + \
          sorted(root.glob("theory/*/main.c")) + \
          sorted(root.glob("extensions/*/main.c")) + \
          sorted(root.glob("templates/C51_Empty/main.c"))

failed = []

for main in targets:
    cmd = [
        "gcc",
        "-DHOST_CHECK",
        "-std=c99",
        "-Wno-main",
        "-Wno-unused-function",
        "-Wno-unused-variable",
        "-fsyntax-only",
        str(main),
    ]
    r = subprocess.run(cmd, cwd=main.parent, capture_output=True, text=True)
    status = "PASS" if r.returncode == 0 else "FAIL"
    print(f"{status:4}  {main.relative_to(root)}")
    if r.returncode != 0:
        failed.append((main, r.stderr))

if failed:
    print("\nFailures:")
    for main, err in failed:
        print(f"\n--- {main} ---\n{err}")
    sys.exit(1)

print(f"\nAll {len(targets)} source targets passed HOST_CHECK syntax validation.")
