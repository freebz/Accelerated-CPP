class Node {
    virtual Node* clone() const = 0;
};


class 클래스-이름;


class Yang; // 전방 선언문

class Yin {
    Yang y;
};

class Yang {
    Yin y;
};
