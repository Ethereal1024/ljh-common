#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_pcd_file>" << std::endl;
        return -1;
    }

    std::string filename = argv[1];

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());

    if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *cloud) == -1) {
        PCL_ERROR("Couldn't read file %s \n", filename.c_str());
        return -1;
    }

    std::cout << "Loaded " << cloud->width * cloud->height << " data points from " << filename << std::endl;

    std::string title = "View " + filename;
    pcl::visualization::CloudViewer viewer(title);
    viewer.showCloud(cloud);

    while (!viewer.wasStopped()) {
    }

    return 0;
}