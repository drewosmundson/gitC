#!/bin/bash



help() { 
    echo "Usage: $./exeToPATH (Options) (/path/to/exe)"

    echo "./exeToPATH"
    echo "  The name of this script. Ensure that it has the correct permissions so that it is able to execute. "
    echo "  If $./exeToPath fails to execute then use the chmod command. "
    echo "  $chmod +x ./exeToPath "

    echo "Options:"
    echo "  help //lists the set of commands and their uses."

    echo "  -c, -check //checks if the executable is already in the PATH. This is also the default option if no arg is given."

    echo "  -i, -install //adds the path to the specified executable to the PATH variable. If none specified promt user"

    echo "  -u, -uninstall //unistalls the script if no executable specified prompt the user"

    echo "/path/to/exe:"
    echo "  The executable exe to be added to the PATH"
}
check() { 
  if [ type -P $exe ]; then 
    return true
  else
    return false
  fi
}

install() {
  if [ check $exe -eq true ]; then
    uninstall $exe
  fi
}

uninstall() {
  if [ check $exe -eq false ]; then
    return true;
  fi
}


main(){
  #check for parameters if none then promt for exe path and list the help command
  if [ "$#" -lt 1 ]; then 
    echo "Enter the path to the executable you would like to install in your PATH"
    echo "Usage: $./exeToPATH path/to/your/exe -options"
    echo "For a list of commands type $./exeToPATH help"
    exit 0
  fi
  
  if [ $1 -eq "help" ] || [ $2 -eq "help" ]; then
    help
  fi

  if [ -x $1 ]; then
    exe=$1
  else 
    echo "Specified exe is not an executable."
    echo "Make sure your exe has the right permissions and has no complation errors"
    exit 1
  fi


  if [ $2 -eq "-c"] || [ $2 -eq "-check"]; then
    if [ check $exe -eq true ]; then
      echo "This executable is in  PATH"
    else
      echo "this executable is not in PATH"
    fi

  elif [ $2 -eq "-i"] || [ $2 -eq "-install"]; then
    install $exe

  elif [ $2 -eq "-u"] || [ $2 -eq "-uninstall"]; then
    uninstall $exe

  fi
    
}


main
echo "Script exiting normally"
exit 0


Code

#!/bin/bash

# Define the source and destination paths
SOURCE_EXECUTABLE="my_c_program" # Replace with your compiled C executable name
INSTALL_DIR="/usr/local/bin" # Common location for user-installed executables

# Check if the source executable exists
if [ ! -f "$SOURCE_EXECUTABLE" ]; then
    echo "Error: Compiled C executable '$SOURCE_EXECUTABLE' not found in the current directory."
    exit 1
fi

# Check if the install directory exists, create if not
if [ ! -d "$INSTALL_DIR" ]; then
    echo "Creating installation directory: $INSTALL_DIR"
    sudo mkdir -p "$INSTALL_DIR" || { echo "Error: Could not create directory $INSTALL_DIR. Check permissions."; exit 1; }
fi

# Copy the executable to the installation directory
echo "Copying '$SOURCE_EXECUTABLE' to '$INSTALL_DIR'..."
sudo cp "$SOURCE_EXECUTABLE" "$INSTALL_DIR/" || { echo "Error: Could not copy executable. Check permissions."; exit 1; }

# Make the executable runnable
echo "Setting executable permissions for '$INSTALL_DIR/$SOURCE_EXECUTABLE'..."
sudo chmod +x "$INSTALL_DIR/$SOURCE_EXECUTABLE" || { echo "Error: Could not set permissions. Check permissions."; exit 1; }

echo "Installation complete. '$SOURCE_EXECUTABLE' is now available in your PATH."
echo "You may need to open a new terminal or run 'source ~/.bashrc' (or similar) for changes to take effect if you modified your PATH manually."
