OPT=$(dialog --menu "Select Difficulty" 10 50 5  1 Easy 2 Medium 3 Hard --output-fd 1);
clear
./maze $OPT