g++ -std=c++14 main.cpp -o main
g++ -std=c++14 gen_tester.cpp -o gen_tester
g++ -std=c++14 sol.cpp -o sol
g++ -std=c++14 sol_fast.cpp -o sol_fast

var="sumcifcmp"

rm -rf tests
mkdir tests

mkdir aux

./gen_tester $var

for i in {1..20};
do
    ./main $i sol sol_fast $var < aux/$i.in
done

rm -rf aux
rm tests.zip
zip -r tests.zip tests

exit 0