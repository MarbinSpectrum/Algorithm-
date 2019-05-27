
namespace Bridge_Pattern
{
    class Program
    {
        static void Main(string[] args)
        {
            //추상층
            Abstraction ab = new RefinedAbstraction();


            //구현층
            ab.Implementor = new ConcreteImplementorA();
            ab.Operation();

            ab.Implementor = new ConcreteImplementorB();
            ab.Operation();

            //Abstraction안의 Implementor를 쓰면되서 Implementor를 만들필요가 없다.
            //Abstraction를 통해서 선언만 함으로서 Implementor 사용가능하다.
            //다른 것도 선언만 함으로써 사용하고 싶다면 Abstraction안에 추가해주면됨 (추상층과 구현층이 분리되어있기 때문)
            //이것이 구현층과 추상층이 분리되어있는 패턴인 브릿지패턴

        }
    }
}
