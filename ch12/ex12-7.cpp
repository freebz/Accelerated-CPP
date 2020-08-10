const std::string greeting = "Hello, " + name + "!";


const Str greeting = "Hello, " + name + "!";


"Hello, " + name


("Hello, " + name) + "!"


Str greeting = "Hello, " + name + "!";


Str temp1("Hello, "); // Str::Str(const char*)
Str temp2 = temp1 + name; // operator+(const Str&, const Str&)
Str temp3("!") // Str::Str(const char*)
Str greeting = temp2 + temp3; // operator+(const Str&, const Str&)
