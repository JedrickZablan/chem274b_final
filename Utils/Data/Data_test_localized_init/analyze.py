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

def cell_analyze_grid(grid):
        #Initializes variables for different cell states
        total_cells = grid.size 
        tumor_cells = np.sum(grid == 1) 
        healthy_cells = np.sum(grid == 0)
        tumor_percents = (tumor_cells / total_cells) * 100

        return {
            "Total Cells" : total_cells, "Tumor Cells" : tumor_cells, "Healthy Cells" : healthy_cells, "Percentage of Tumor Cells" : tumor_percents #Returns a dictionary of the values
        }

#Sorts the CA_state_report files by ascending order
def sort_output(directory_path):
    filename_parts = [] #Empty list that will later be used to store the common file name and the ascending numbers
    for filename in os.listdir(directory_path): #Iterate throuhg the files in the directory
        if filename.endswith(".txt") and filename.startswith("CA_state_report_"): #Checks if the file has this naming convention
            report_number = int(filename.split("_")[3].split(".")[0]) #Splits the number of the report from the file name
            filename_parts.append((filename, report_number)) #Appends the filename and the number to a list
    sort_filename_parts = sorted(filename_parts, key=lambda x: x[1]) #Sorts the files by the report_number

    return sort_filename_parts

#Plots the data for healthy cells, tumor cells and percentage of tumor cells
def plot_states(time_steps, healthy_cells, tumor_cells, tumor_percent):
    fig, ax1 = plt.subplots(figsize=(8, 4.5)) #Initializes the size of the plot
    ax2 = ax1.twinx() #Sets the plot two have two y axis

    #Plots the first graph for the healthy and tumor cell count
    ax1.set_xlabel("Time")
    ax1.set_ylabel("Cells in This Stage", color = "black")
    ax1.plot(time_steps, healthy_cells, marker = "o", linestyle = "-", color = "g", label = "Healthy Cells")
    ax1.plot(time_steps, tumor_cells, marker = "o", linestyle = "-", color = "r", label = "Tumor Cells")
    ax1.tick_params(axis = "y", labelcolor = "black")
    ax1.legend(loc = "upper left")

    #Plots the percent of tumor cells out of total cells
    ax2.set_ylabel("Percentage of Tumor Cells", color="blue")  
    ax2.plot(time_steps, tumor_percent, marker = "D", linestyle = "--", color = "b", label = "Percentage of Tumor Cells")
    ax2.tick_params(axis = "y", labelcolor = "b")
    ax2.legend(loc = "center right")

    plt.title("Cell Counts and Tumor Percentage Over Time")
    fig.tight_layout()  
    # plt.show()
    plt.savefig("plot_states.png") 

def main(directory_path):
    #Intializes empty lists for the plot data
    time_steps = []
    tumor_count = []
    healthy_count = []
    tumor_percent = []

    ascending_order_names = sort_output(directory_path) #Sorts the files in ascending order for the print output
    for filename, report_number in ascending_order_names: #Iterates the filename and report_number through the sort
        if filename.endswith('.txt'):
            filepath = os.path.join(directory_path, filename)
            time_step, grid = read_grid_file(filepath)
            plot_grid(grid, time_step, save_path=f"{directory_path}/plot_{time_step}.png")
            cell_states = cell_analyze_grid(grid)
            print(f"Cell States for '{filename} {time_step}: {cell_states}")

            int_time_step = int(time_step.split(': ')[-1]) #Splits "At Time Step: number" to assign the number to int_time_step
            time_steps.append(int_time_step) #Appends the number for time
            #Appends data from dictionary to empty list
            tumor_count.append(cell_states["Tumor Cells"]) 
            healthy_count.append(cell_states["Healthy Cells"]) 
            tumor_percent.append(cell_states["Percentage of Tumor Cells"]) 

    plot_states(time_steps, healthy_count, tumor_count, tumor_percent) #Plots the line graph 
            
# Replace '/path/to/directory' with the path to your directory containing .txt files
main('.')
