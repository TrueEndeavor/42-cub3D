#!/bin/bash


# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Directory containing your map files
MAP_DIR="maps"
EXPECTED_DIR="maps/expected_outputs"

# Array of map files to test
MAP_FILES=(
	"bad/color_invalid_rgb.cub"
	"bad/color_missing_ceiling_rgb.cub"
	"bad/color_missing_floor_rgb.cub"
	"bad/color_missing.cub"
	"bad/color_none.cub"
	"bad/empty.cub"
	"bad/file_letter_end.cub"
	"bad/filetype_missing"
	"bad/filetype_wrong.buc"	
	"bad/map_first.cub"
	"bad/map_middle.cub"
	"bad/map_missing.cub"
	"bad/map_only.cub"
	"bad/map_too_small.cub"
	"bad/player_multiple.cub"
	"bad/player_none.cub"
	"bad/player_on_edge.cub"	
	"bad/textures_dir.cub"
	"bad/textures_duplicates.cub"
	"bad/textures_invalid.cub"
	"bad/textures_missing.cub"
	"bad/textures_none.cub"
	"bad/textures_not_xpm.cub"
	"bad/wall_hole_east.cub"
	"bad/wall_hole_north.cub"
	"bad/wall_hole_south.cub"
	"bad/wall_hole_west.cub"
	"bad/wall_none.cub"
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
	EXPECTED_FILE="$EXPECTED_DIR/$(basename $map_file)"
	
   if [ -f "$EXPECTED_FILE" ]; then
		EXPECTED_OUTPUT=$(cat "$EXPECTED_FILE")
		
		if [ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
			((TESTS_PASSED++))
			echo -e "${GREEN}Test $TEST_NUMBER OK.${NC}"
			echo -e "${GREEN}Expected:" $EXPECTED_OUTPUT "${NC}"
			echo -e "${GREEN}Actual  :" $ACTUAL_OUTPUT "${NC}"
		else
			echo -e "${RED}Test $TEST_NUMBER: KO${NC}"
			echo -e "Expected:" $EXPECTED_OUTPUT "${NC}"
			echo -e "${RED}Actual  :" $ACTUAL_OUTPUT "${NC}"
		fi
	else
		echo -e "${RED}Expected output file not found for $map_file${NC}"
	fi

	echo "-------------------------"
done

# Print total tests passed
echo -e "Total tests passed: ${GREEN}$TESTS_PASSED${NC}/$TEST_NUMBER"