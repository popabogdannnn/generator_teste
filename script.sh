g++ -std=c++14 main.cpp -o main
g++ -std=c++14 gen_tester.cpp -o gen_tester
g++ -std=c++14 sol.cpp -o sol
g++ -std=c++14 sol_fast.cpp -o sol_fast

./gen_tester "test"

for i in {1..20};
do
    ./main $i sol sol_fast date < $i.in
done

exit 0