import os
import shutil

def remove_file(file_path):
    try:
        os.remove(file_path)
        print(f"File {file_path} removed successfully.")
    except FileNotFoundError:
        print(f"File {file_path} does not exist.")
    except PermissionError:
        print(f"No permission to delete {file_path}.")
    except Exception as e:
        print(f"Error removing file: {e}")
        
def remove_directory(directory_path):
    try:
        shutil.rmtree(directory_path)
        print(f"Directory {directory_path} removed successfully.")
    except FileNotFoundError:
        print(f"Directory {directory_path} does not exist.")
    except PermissionError:
        print(f"No permission to delete {directory_path}.")
    except Exception as e:
        print(f"Error removing directory: {e}")
        
def make_directory(directory_path):
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)
        print(f"Directory '{directory_path}' created successfully.")
    else:
        print(f"Directory '{directory_path}' already exists.")