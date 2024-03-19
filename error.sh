echo "TEST ALL ERROR MAP"

echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/bad_char.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/empty.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/exit_no_acces.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/gigantus.ber
sleep 2
echo "=============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/miss_one.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/no_collectibles.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/no_exit.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/not_closed.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/tiny.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/too_character.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/too_exit.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/wtf.ber
sleep 2
echo "============================================================================================"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/same_size.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/wrong_ext.c
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/chmod_map.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/bad_door.ber
sleep 2
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/bad_door_2.ber
sleep 2
echo "============================================================================================="
