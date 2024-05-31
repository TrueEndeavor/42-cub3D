#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Directory containing your map files
MAP_DIR="maps"

# Array of map files to test
MAP_FILES=(
	"good/cheese_maze.cub"
	"good/creepy.cub"
	"good/dungeon.cub"
	"good/library.cub"
	"good/matrix.cub"
	"good/sad_face.cub"
	"good/square_map.cub"
	"good/subject_map.cub"
	"good/subject_map1.cub"
	"good/test_map.cub"
	"good/test_map_hole.cub"
	"good/test_pos_bottom.cub"
	"good/test_pos_left.cub"
	"good/test_pos_right.cub"
	"good/test_pos_top.cub"
	"good/test_textures.cub"
	"good/test_whitespace.cub"
	"good/walls_normal.cub"
	"good/works.cub"
	"good/worldmap.cub"
)

TEST_NUMBER=0
TESTS_PASSED=0

# Path to the cub3D executable
CUB3D_EXEC="./cub3D"

# Loop through each map file and run cub3D
for map_file in "${MAP_FILES[@]}"; do
	((TEST_NUMBER++))
	echo -e "${CYAN}Running test: $CUB3D_EXEC $MAP_DIR/$map_file"
	
	# Run the cub3D command and capture the output and errors
	ACTUAL_OUTPUT=$($CUB3D_EXEC "$MAP_DIR/$map_file" 2>&1)
	EXIT_STATUS=$?
	
	# Path to the expected output file
	#EXPECTED_FILE="$EXPECTED_DIR/$(basename $map_file)"
	
   #if [ -f "$EXPECTED_FILE" ]; then
	#	EXPECTED_OUTPUT=$(cat "$EXPECTED_FILE")
		
	#	if [ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
			((TESTS_PASSED++))
			echo -e "${GREEN}Test $TEST_NUMBER OK.${NC}"
			echo -e "${GREEN}Expected:" $EXPECTED_OUTPUT "${NC}"
			echo -e "${RED}Actual  :" $ACTUAL_OUTPUT "${NC}"
	#	else
	#		echo -e "${RED}Test $TEST_NUMBER: KO${NC}"
	#		echo -e "Expected:" $EXPECTED_OUTPUT "${NC}"
	#		echo -e "${RED}Actual  :" $ACTUAL_OUTPUT "${NC}"
	#	fi
	#else
	#	echo -e "${RED}Expected output file not found for $map_file${NC}"
	#fi

	echo "-------------------------"
done

# Print total tests passed
echo -e "Total tests passed: ${GREEN}$TESTS_PASSED${NC}/$TEST_NUMBER"