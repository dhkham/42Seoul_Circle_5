#!/bin/bash

make all

echo "value : "
./convert ""
echo ""

echo "value : 0"
./convert 0
echo ""

echo "value : nan"
./convert nan
echo ""

echo "value : 42.0f"
./convert 42.0f
echo ""

echo "value : -42.0f"
./convert -42.0f
echo ""

echo "value : -42f0f"
./convert -42f0f
echo ""

echo "value : wefwefwfe"
./convert wefwefwfe
echo ""

echo "value : 42.0fffffffff"
./convert 42.0fffffffff
echo ""

echo "value : 11111111111111111111111111111111111111111111111111"
./convert 11111111111111111111111111111111111111111111111111
echo ""

echo "value : 11111111111111111111111111111111111111111111111111.1"
./convert 11111111111111111111111111111111111111111111111111.1
echo ""

echo "value : -11111111111111111111111111111111111111111111111111.1"
./convert -11111111111111111111111111111111111111111111111111.1
echo ""

echo "value : 2147483648"
./convert 2147483648
echo ""

echo "value : *"
./convert "*"

make fclean
