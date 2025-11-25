#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Hot60_clicked();

    void on_Hot60Pro_clicked();

    void on_MainMenu_clicked();

    void on_Hot60ProPlus_clicked();

    void on_Hot60i_clicked();

    void on_Note50ProPlus_clicked();

    void on_GT30Pro_clicked();

    void on_Note50_clicked();

    void on_Smart9_clicked();

    void on_ZeroFlip_clicked();

    void on_Hot50Pro_clicked();

    void on_SpecComparison_clicked();

    void on_SearchMenuButton_clicked();

    void on_Infinix_clicked();

    void on_K13TurboPro_clicked();

    void on_Oppo_clicked();

    void on_K13Turbo_clicked();

    void on_Reno14Pro_clicked();

    void on_Reno14_clicked();

    void on_FindX8Ultra_clicked();

    void on_FinX8splus_clicked();

    void on_FindX8s_clicked();

    void on_FindN5_clicked();

    void on_Reno13Pro_clicked();

    void on_Reno13_clicked();

    void on_K80Ultra_clicked();

    void on_Note14ProPlus_clicked();

    void on_A5_clicked();

    void on_Turbo4_clicked();

    void on_Note14Pro_clicked();

    void on_Note14_clicked();

    void on_A3X_clicked();

    void on_A3_clicked();

    void on_Redmi14C_clicked();

    void on_Redmi12_clicked();

    void on_Redmi_clicked();

    void on_HTC_clicked();

    void on_Apple_clicked();

    void on_Nokia_clicked();

    void on_LG_clicked();

    void on_Samsung_clicked();

    void on_Sony_clicked();

    void on_Xiaomi_clicked();

    void on_Vivo_clicked();

    void on_Motorola_clicked();

    void on_proMax16_clicked();

    void on_Pro16_clicked();

    void on_Plus16_clicked();

    void on_sixteen_clicked();

    void on_e16_clicked();

    void on_PRoMax15_clicked();

    void on_Pro15_clicked();

    void on_Plus15_clicked();

    void on_fifthteen_clicked();

    void on_ProMax14_clicked();

    void on_SearchButton_clicked();

    void on_Huawei_clicked();

    void on_Microsoft_clicked();

    void on_U23Pro_clicked();

    void on_Desire22Pro_clicked();

    void on_U20_clicked();

    void on_Desire21Pro_clicked();

    void on_WildfireE3_clicked();

    void on_WildfireR70_clicked();

    void on_U12plus_clicked();

    void on_Exodus1_clicked();

    void on_Desire20plus_clicked();

    void on_OneM9_clicked();

    void on_G42_clicked();

    void on_XR21_clicked();

    void on_XR20_clicked();

    void on_C32_clicked();

    void on_G60_clicked();

    void on_G42_2_clicked();

    void on_G400_clicked();

    void on_G310_clicked();

    void on_Nokia220_clicked();

    void on_Nokia235_clicked();

    void on_Wing_clicked();

    void on_Velvet_clicked();

    void on_G8ThinQ_clicked();

    void on_V60ThinQ_clicked();

    void on_K92_clicked();

    void on_Stylo6_clicked();

    void on_G7ThinQ_clicked();

    void on_V50ThinQ_clicked();

    void on_Q70_clicked();

    void on_V40ThinQ_clicked();

    void on_Ultra24_clicked();

    void on_Plus24_clicked();

    void on_S24_clicked();

    void on_Fold5_clicked();

    void on_Flip5_clicked();

    void on_Ultra23_clicked();

    void on_Plus23_clicked();

    void on_A74_clicked();

    void on_A54_clicked();

    void on_A34_clicked();

    void on_VI1_clicked();

    void on_V5_clicked();

    void on_V10_clicked();

    void on_ProI_clicked();

    void on_IV1_clicked();

    void on_IV5_clicked();

    void on_IV10_clicked();

    void on_Pro_clicked();

    void on_III1_clicked();

    void on_III5_clicked();

    void on_C13_clicked();

    void on_Note13_clicked();

    void on_Pro13_clicked();

    void on_X5Pro_clicked();

    void on_Lite12_clicked();

    void on_Mi11Ultra_clicked();

    void on_K70Pro_clicked();

    void on_Pad6Pro_clicked();

    void on_Civi4Pro_clicked();

    void on_MixFold3_clicked();

    void on_X60_clicked();

    void on_X60Pro_clicked();

    void on_X50_clicked();

    void on_X50Pro_clicked();

    void on_Y20_clicked();

    void on_Y51_clicked();

    void on_S1_clicked();

    void on_V15_clicked();

    void on_V17_clicked();

    void on_iQOO_clicked();

    void on_Edge40Pro_clicked();

    void on_Edge40_clicked();

    void on_Edge30Ultra_clicked();

    void on_Edge30Fusion_clicked();

    void on_Edge30Pro_clicked();

    void on_Edge30_clicked();

    void on_Edge20Pro_clicked();

    void on_Edge20Lite_clicked();

    void on_Edge_clicked();

    void on_EdgePlus_clicked();

    void on_Pura70Ultra_clicked();

    void on_Pura70Pro_clicked();

    void on_Pura70_clicked();

    void on_MateX6_clicked();

    void on_MateX5UltimateDesign_clicked();

    void on_Mate50Pro_clicked();

    void on_Mate50_clicked();

    void on_Nova12Pro_clicked();

    void on_Nova12SE_clicked();

    void on_Nova12i_clicked();

    void on_SurfaceDuo_clicked();

    void on_SurfaceDuo2_clicked();

    void on_Lumina950_clicked();

    void on_Lumina1020_clicked();

    void on_Lumina650_clicked();

    void on_KinTwo_clicked();

    void on_Tecno_clicked();

    void on_S20Proplus_clicked();

    void on_S10Pro_clicked();

    void on_S9Pro_clicked();

    void on_S8Pro_clicked();

    void on_S7Pro_clicked();

    void on_S6_clicked();

    void on_S5Pro_clicked();

    void on_S4_clicked();

    void on_S3Pro_clicked();

    void on_S2_clicked();

    void on_ZTE_clicked();

    void on_NubiaZ70SUltra_clicked();

    void on_NubiaFlip2_clicked();

    void on_NubiaFocus2512_clicked();

    void on_NubiaFocus2256_clicked();

    void on_NubiaNeo3G_clicked();

    void on_NubiaNeo4G_clicked();

    void on_NubiaNeo5G_clicked();

    void on_NubiaMusic2_clicked();

    void on_Axon60Ultra_clicked();

    void on_Axon40Ultra_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_add_clicked();

    void on_remove_clicked();

    void on_COMPARE_clicked();

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

    void on_github_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
