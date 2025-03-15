#include "config.h"

sf::RenderWindow window(sf::VideoMode(800u, 600u), "SFML works!", sf::Style::Default);

unsigned int windowWidth = 800;
unsigned int windowHeight = 600;
int line::id_cnt = 0;
std::unordered_map<std::string, point*> points;
std::unordered_map<int, line*> lines;

void cmd_thread()
{ // 通过命令增减对象
    system("cls");
    int point_name_cnt = 0; // for unnamed points
    while (true)
    {
        std::cout << " >>> ";
        std::string tmp;
        std::getline(std::cin, tmp);
        std::stringstream cmd(tmp);
        std::string op;
        cmd >> op;
        std::queue<std::string> args;
        while (cmd >> tmp)
            args.push(tmp);
        std::cout << "cmd length : " << args.size() + 1 << std::endl;
        if (op == "exit")
            return;
        else if (op == "add")
        {
            if (args.empty())
                continue;
            if (args.front() == "point")
            {
                args.pop();
                std::string name = args.empty() ? std::string("unnamed point ") + std::to_string(point_name_cnt++) : args.front(); args.pop();
                sf::Vector2d position;
                if (args.empty())
                    position = {0.0, 0.0};
                else
                {
                    position.x = std::stod(args.front()); args.pop();
                    if (args.empty())
                    {
                        std::cout << "Error: missing y coordinate\n";
                        continue;
                    }
                    else
                    {
                        position.y = std::stod(args.front());
                        args.pop();
                    }
                }
                if (points.find(name) != points.end())
                {
                    std::cout << "Error: point " << name << " already exists\n";
                    continue;
                }
                point* p = new point{name, position, sf::Color(rand() % 256, rand() % 256, rand() % 256)};
                points[name] = p;
                std::cout << "Point " << name << " added at " << position.x << ", " << position.y << '\n';
            }
        }
    }
}

int main()
{
    sf::Thread cmd(cmd_thread);
    cmd.launch();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        window.display();
    }
    cmd.wait();
    for (auto &p : points)
        delete p.second;
    for (auto &l : lines)
        delete l.second;
    return 0;
}
