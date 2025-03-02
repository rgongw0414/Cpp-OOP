class Entity {
public:
    int getX() const {
        m_getXCount_debug++;
        return s_x;
    }

    int getDebugCount() const {
        return m_getXCount_debug; // for the sake of debugging
    }
private:
    mutable int m_getXCount_debug = 0; // mutable allows to modify a member in a const function
    int s_x;
};