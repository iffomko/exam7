#include <iostream>
#include <fstream>

class thing {
    std::string title;
    double weight;
    int prof;
public:
    thing() {};

    thing(std::string title, double weight, int prof) {
        this->title = title;
        this->weight = weight;
        this->prof = prof;
    }

    std::string getTitle() {
        return this->title;
    }
    double getWeight() {
        return this->weight;
    }
    int getProf() {
        return this->prof;
    }

    void setTitle(std::string title) {
        this->title = title;
    }

    void setWeight(double weight) {
        this->weight = weight;
    }

    void setProf(int prof) {
        this->prof = prof;
    };
};

thing* read(std::ifstream &fin, int &n) {
    thing* arr = nullptr;

    if (!fin) {
        std::cout << "Failed!\n";
    } else {
        fin >> n;

        arr = new thing[n];

        for (int i = 0; i < n; i++) {
            std::string title;
            double weight;
            int prof;

            fin >> title >> weight >> prof;

            arr[i].setTitle(title);
            arr[i].setWeight(weight);
            arr[i].setProf(prof);
        }
    }

    fin.close();

    return arr;
}

int main() {
    std::ifstream fin("C:\\projectN\\input.txt");

    int n;

    thing* arr = read(fin, n);

    if (arr != nullptr) {
        int key, count = 0;
        int* indexes = new int[n];

        std::cout << "Enter prof: ";
        std::cin >> key;

        for (int i = 0; i < n; i++)
            if (arr[i].getProf() == key) {
                indexes[count] = i;
                count++;
            }

        if (count == 0) {
            std::cout << "Nope, sorry..\n";
//            return 0;
        }

        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (arr[indexes[i]].getWeight() > arr[indexes[j]].getWeight()) {
                    thing temp = arr[indexes[i]];
                    arr[indexes[i]] = arr[indexes[j]];
                    arr[indexes[j]] = temp;
                }

        for (int i = 0; i < count; i++)
            std::cout << arr[indexes[i]].getTitle() << " " << arr[indexes[i]].getProf() << " " << arr[indexes[i]].getWeight() << std::endl;
    }

    return 0;
}
