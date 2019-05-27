using System;

namespace Singleton_Pattern
{
    public class Singleton
    {
        private static Singleton gInstance = new Singleton();

        public String StudyNumber = "2014335003";
        private Singleton()
        {
        }

        public static Singleton getInstance() {
            return gInstance;
        }
    }
}
