struct BaseClass {};
struct DerivedClass : BaseClass {};
void are_belong_to_us(BaseClass& base) {}

int main() {
  DerivedClass derived;
  are_belong_to_us(derived);
}
