import os

def steps_geo(min_n=100, max_n=100_000_000, ratio=1.5):
    n, out = min_n, []
    while n <= max_n:
        out.append(int(n))
        n = max(n + 1, int(n * ratio))
    return out

types= [ "cpp", "gd" ]
for type in types:
    for N in steps_geo(100, 1e8):
        os.system(f"run.console.exe --headless --type {type} --iters {N}")