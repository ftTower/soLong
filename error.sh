echo "TEST ALL ERROR MAP"

echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/bad_char.ber
sleep 5
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/empty.ber
sleep 5
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/exit_no_acces.ber
sleep 5
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/gigantus.ber
sleep 5
echo "=============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/miss_one.ber
sleep 5
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/no_collectibles.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/no_exit.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/not_closed.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/tiny.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/too_character.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/too_exit.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/wtf.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/same_size.ber
echo "============================================================================================="
