#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct City{
    vector<City*> link;
    string name;  // Thêm tên thành phố để dễ hiển thị
    int data;
    
    City(string n = "") : name(n), data(0) {}
};

void route2chieu(City &a, City &b){
    a.link.push_back(&b);
    b.link.push_back(&a);
}

void route1chieu(City &noi, City &duoc_noi){
    noi.link.push_back(&duoc_noi);
}

// Hàm tìm đường đi ngắn nhất bằng BFS (không trọng số)
vector<City*> findShortestPath(City* start, City* end) {
    if (start == end) return {start};
    
    queue<City*> q;
    map<City*, City*> previous;  // Lưu đường đi
    map<City*, bool> visited;
    
    q.push(start);
    visited[start] = true;
    previous[start] = nullptr;
    
    while (!q.empty()) {
        City* current = q.front();
        q.pop();
        
        // Nếu đến đích
        if (current == end) {
            // Truy vết đường đi
            vector<City*> path;
            City* node = end;
            while (node != nullptr) {
                path.push_back(node);
                node = previous[node];
            }
            reverse(path.begin(), path.end());
            return path;
        }
        
        // Duyệt các thành phố kề
        for (City* neighbor : current->link) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                previous[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    // Không tìm thấy đường đi
    return {};
}

// Hàm hiển thị đường đi
void printPath(const vector<City*>& path) {
    if (path.empty()) {
        cout << "Không tìm thấy đường đi!" << endl;
        return;
    }
    
    cout << "Đường đi ngắn nhất: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i]->name;
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
    cout << "Độ dài đường đi: " << path.size() - 1 << " bước" << endl;
}

int main() { 
    // Khởi tạo các thành phố với tên
    City ThaiNguyen("Thái Nguyên"), HaNoi("Hà Nội"), SonTay("Sơn Tây");
    City HoaBinh("Hòa Bình"), PhuLy("Phủ Lý"), HungYen("Hưng Yên");
    City HaiDuong("Hải Dương"), BacNinh("Bắc Ninh"), BacGiang("Bắc Giang");
    City UongBi("Uông Bí"), HaiPhong("Hải Phòng");
    
    // Thiết lập các tuyến đường
    route2chieu(HaNoi, ThaiNguyen);
    route2chieu(HaNoi, SonTay);
    route2chieu(HaNoi, HoaBinh);
    route2chieu(HaNoi, PhuLy);
    route2chieu(HaNoi, HungYen);
    route2chieu(HaNoi, HaiDuong);
    route2chieu(HaNoi, BacNinh);
    route2chieu(BacNinh, BacGiang);
    route2chieu(BacGiang, UongBi);
    route2chieu(BacNinh, UongBi);
    route2chieu(UongBi, HaiPhong);
    route2chieu(HaiDuong, HaiPhong);
    route2chieu(HaiDuong, HungYen);
    route2chieu(HungYen, PhuLy);
    
    // Tìm đường đi ngắn nhất từ Hà Nội đến Hải Phòng
    cout << "=== TÌM ĐƯỜNG ĐI NGẮN NHẤT ===" << endl;
    vector<City*> path1 = findShortestPath(&HaNoi, &HaiPhong);
    printPath(path1);
    
    cout << "\n=== TÌM ĐƯỜNG ĐI KHÁC ===" << endl;
    vector<City*> path2 = findShortestPath(&BacNinh, &PhuLy);
    printPath(path2);
    
    // Tìm tất cả đường đi (nếu cần)
    cout << "\n=== TÌM TẤT CẢ ĐƯỜNG ĐI ===" << endl;
    // Có thể thêm hàm findAllPaths nếu cần
    
    return 0;
}