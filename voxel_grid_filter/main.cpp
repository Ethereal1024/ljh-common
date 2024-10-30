#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <iostream>

int main(int argc, char** argv) {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());

    if (pcl::io::loadPCDFile<pcl::PointXYZ>("input.pcd", *cloud) == -1) {
        PCL_ERROR("Couldn't read file input.pcd \n");
        return (-1);
    }
    std::cout << "Loaded " << cloud->width * cloud->height << " data points from input.pcd" << std::endl;

    pcl::VoxelGrid<pcl::PointXYZ> vg;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    vg.setInputCloud(cloud);
    vg.setLeafSize(0.01f, 0.01f, 0.01f);
    vg.filter(*cloud_filtered);
    std::cout << "Voxel Grid filter applied, new point cloud size: " << cloud_filtered->points.size() << std::endl;

    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud_filtered);
    sor.setMeanK(50);
    sor.setStddevMulThresh(1.0);
    sor.filter(*cloud_filtered);
    std::cout << "Statistical Outlier Removal filter applied, new point cloud size: " << cloud_filtered->points.size() << std::endl;

    pcl::io::savePCDFileASCII("filtered_statistical.pcd", *cloud_filtered);

    return 0;
}