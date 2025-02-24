import subprocess
import itertools
import os
import sys
from time import sleep

def compile_app():
    """
    Recompiles the application using make re
    Returns True if compilation successful, False otherwise
    """
    print("Compiling application...")
    try:
        result = subprocess.run(
            ["make", "re"], 
            capture_output=True, 
            text=True,
            cwd=os.getcwd()
        )
        
        if result.returncode != 0:
            print("❌ Compilation failed!")
            print(result.stderr)
            return False
            
        print("✅ Compilation successful!")
        return True
        
    except Exception as e:
        print(f"❌ Compilation error: {e}")
        return False

def try_password(executable_name, username, password):
    """
    Attempts to login with given credentials
    Returns True if successful, False otherwise
    """
    try:
        # Start the process
        process = subprocess.Popen(
            [f"./{executable_name}"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            text=True
        )
        
        # Send username
        process.stdin.write(f"{username}\n")
        process.stdin.flush()
        
        # Send password
        process.stdin.write(f"{password}\n")
        process.stdin.flush()
        
        # Get output
        output = process.communicate()[0]
        
        # Check if password was correct
        return "Correct password" in output
        
    except Exception as e:
        print(f"Error occurred: {e}")
        return False

def main():
    # Get executable name from command line or use default
    compile_app()
    executable_name = "bf"
    username = "test_user"
    
    print(f"Starting brute force attack on {executable_name}...")
    print(f"Testing all possibilities from 0000-9999")
    
    # Try all possible 4-digit combinations
    for i in range(10000):
        password = f"{i:04d}"  # Format as 4 digits with leading zeros
        print(f"\rTrying password: {password}", end="")
        
        if try_password(executable_name, username, password):
            print(f"\nPassword found: {password}")
            return
            
    print("\nPassword not found")

if __name__ == "__main__":
    main()
