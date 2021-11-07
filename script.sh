g++ -std=c++14 main.cpp -o main

for i in {1..2};
do
    ./main $i sol date < $i.in
done

exit 0