import matplotlib.pyplot as plt
import os
import numpy as np

def read_grid_file(filepath):
    with open(filepath, 'r') as file:
        time_step = file.readline().strip()
        grid = [list(map(int, line.split())) for line in file]
    return time_step, np.array(grid)

def plot_grid(grid, time_step, save_path=None):
    color_map = {0: [0, 1, 0, 1], 1: [1, 0, 0, 1], 2: [1, 1, 0, 1]}  # RGB color codes with alpha value
    colored_grid = np.zeros((grid.shape[0], grid.shape[1], 4))  # Initialize a grid with shape (rows, cols, RGBA)

    for i in range(grid.shape[0]):
        for j in range(grid.shape[1]):
            colored_grid[i, j] = color_map[grid[i, j]]

    plt.figure(figsize=(5, 5))
    plt.imshow(colored_grid, interpolation='nearest')
    plt.title(f'Time step: {time_step}')
    plt.xticks([]), plt.yticks([])  # Hide axis ticks

    if save_path:
        plt.savefig(save_path)
    else:
        plt.show()
    plt.close()

def main(directory_path):
    for filename in os.listdir(directory_path):
        if filename.endswith('.txt'):
            filepath = os.path.join(directory_path, filename)
            time_step, grid = read_grid_file(filepath)
            plot_grid(grid, time_step, save_path=f"{directory_path}/plot_{time_step}.png")

# Replace '/path/to/directory' with the path to your directory containing .txt files
main('.')
