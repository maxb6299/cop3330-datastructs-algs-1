class Diamond
{
private:
    int size;
    char border;
    char fill;
    
public:

    // constructor
    Diamond(int size, char border='#', char fill='*');

    // getters
    int GetSize();
    int Perimeter();
    double Area();

    // grow/shrink
    void Grow();
    void Shrink();

    // setters
    void SetBorder(char border);
    void SetFill(char fill);

    // draw
    void Draw();

    void Summary();

};