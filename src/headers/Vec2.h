class Vec2
{
private:
    int m_X;
    int m_Y;

    char m_file;
    int m_rank;
public:
    Vec2(const int x, const int y);
    ~Vec2();
    
    int X() const;
    int Y() const;


    void set(const int x, const int y);

    static Vec2 getChessVec2(const char x, const int y);
};


