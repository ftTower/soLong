echo "TEST ALL ERROR MAP"

echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/bad_char.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/empty.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/exit_no_acces.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/gigantus.ber
echo "============================================================================================="
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map/error/miss_one.ber
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
