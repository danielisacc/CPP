#!/bin/bash

# Check if at least 2 arguments are provided (projectName and dirLocation)
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 projectName dirLocation [ClassName1 ClassName2 ... ClassNameN]"
    exit 1
fi

# Assigning arguments to variables
projectName=$1
dirLocation=$2
shift 2  # Shift to get class names

# Create the directories
mkdir -p "$dirLocation/.vscode"
mkdir -p "$dirLocation/src"

# Create the main source file in the src directory
touch "$dirLocation/src/${projectName}.cpp"

# Initialize args array for tasks.json
args=("-fdiagnostics-color=always" "-g" "\${workspaceFolder}/src/${projectName}.cpp")

# Create class files if class names are provided
for className in "$@"; do
    touch "$dirLocation/src/${className}.h"
    touch "$dirLocation/src/${className}.cpp"
    args+=("\${workspaceFolder}/src/${className}.cpp")
done

# Create tasks.json
cat <<EOL > "$dirLocation/.vscode/tasks.json"
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "C/C++: g++ build active file",
            "type": "shell",
            "command": "/usr/bin/g++",
            "args": [
                "${args[@]}",
                "-o",
                "\${workspaceFolder}/${projectName}"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["\$gcc"]
        }
    ]
}
EOL

# Create launch.json
cat <<EOL > "$dirLocation/.vscode/launch.json"
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "\${workspaceFolder}/${projectName}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "\${workspaceFolder}/src",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++ build active file"
        }
    ]
}
EOL

echo "Project $projectName created in $dirLocation"
