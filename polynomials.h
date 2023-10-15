class Polynomial {
    private:
        int degree;
        double* values;
    public:
        explicit Polynomial(int polynomial_level = 0, const double* polynomial_values = nullptr);
        ~Polynomial();
        Polynomial operator+(Polynomial const& b);
        Polynomial operator-(Polynomial const& b);
        Polynomial operator*(Polynomial const& b);
        int getDegree() const;
        double getValue(int n);
        void setValue(int n, double x);
};