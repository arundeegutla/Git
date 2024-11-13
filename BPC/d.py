import math

def calculate_distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

N, R = map(float, input().split())
total_distance = 0

points = []
for _ in range(int(N)):
    x, y = map(float, input().split())
    points.append((x, y))

for i in range(int(N)):
    x1, y1 = points[i]
    x2, y2 = points[(i + 1) % int(N)]
    
    total_distance += calculate_distance(x1, y1, x2, y2)

circumference_wheel = 2 * math.pi * R
rotations = total_distance / circumference_wheel

print(round(rotations, 1))