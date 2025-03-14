#include "config.h"

sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML works!", sf::Style::Default, sf::ContextSettings{0, 0, 0, 2, 0, 0, 0});

unsigned int windowWidth = 800;
unsigned int windowHeight = 600;
int line::id_cnt = 0;
std::unordered_map<std::string, point*> points;
std::unordered_map<int, line*> lines;

int get_sstream_size(std::stringstream& ss)
{
    ss.seekg(0, std::ios::end);
    int size = ss.tellg();
    ss.seekg(0, std::ios::beg);
    return size;
}

void UI_thread()
{ // 显示和鼠标操作图形
    while (window.isOpen())
    {
        while (std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.display();
    }
}

void cmd_thread()
{ // 通过命令增减对象
    while (true)
    {
        system("cls");
        std::cout << " >>> ";
        std::string tmp;
        std::getline(std::cin, tmp);
        std::stringstream cmd(tmp);
        std::string op;
        cmd >> op;
        if (op == "add")
        {
            std::string arg;
            cmd >> arg; // add type
            if (arg == "point")
            {
                cmd >> arg; // point name
                sf::Vector2d pos{0, 0};
                if (get_sstream_size(cmd) == 5)
                    cmd >> pos.x >> pos.y;
                if (points.find(arg) != points.end())
                {
                    std::cout << "point " << arg << " already exists" << std::endl;
                    continue;
                }
                point *p = new point;
                p->position = pos;
                p->color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
                points[p->name] = p;
                std::cout << "point " << arg << " added" << std::endl;
            }
            if (arg == "line")
            { // no name
                std::string p1, p2;
                cmd >> p1 >> p2; // point1 point2
                if (points.find(p1) == points.end())
                {
                    std::cout << "point " << p1 << " not found" << std::endl;
                    continue;
                }
                if (points.find(p2) == points.end())
                {
                    std::cout << "point " << p2 << " not found" << std::endl;
                    continue;
                }
                line *l = new line;
                l->p1 = points[p1];
                l->p2 = points[p2];
                l->color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
                lines[l->id] = l;
                std::cout << "line " << l->id << " added" << std::endl;
            }
        }
    }
}

int main()
{
    std::thread UI(UI_thread);
    std::thread cmd(cmd_thread);
    UI.join();
    cmd.join();
    for (auto &p : points)
        delete p.second;
    for (auto &l : lines)
        delete l.second;
    return 0;
}
