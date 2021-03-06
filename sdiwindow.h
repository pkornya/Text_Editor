#ifndef SDIWINDOW_H
#define SDIWINDOW_H

#include <QMainWindow>

class QTextEdit;
class FindDialog;

class SdiWindow : public QMainWindow
{
    Q_OBJECT

public:
    SdiWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createActions();
    void createMenus();
    void createToolbars();
    void createDocks();
    bool isSafeToClose();
    void readSettings();
    void writeSettings();
    bool saveFile(const QString &filename);
    void loadFile(const QString &filename);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);
    void setCurrentFile(const QString &fileName);

private slots:
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void print();
    void deleteText();
    void openRecentFile();
    void changeFont();
    void changeColor();
    void changeBackgroundColor();
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);
    void find();
    void about();

private:
    QTextEdit   *docWidget;
    QString     currentFilename;
    QDockWidget *dock;
    FindDialog  *findDialog;
    QStringList recentFiles;

    enum { MaxRecentFiles = 5 };

    QMenu       *menu;
    QToolBar    *toolbar;

    QAction     *newAction;
    QAction     *openAction;
    QAction     *saveAction;
    QAction     *saveAsAction;
    QAction     *printAction;
    QAction     *closeAction;
    QAction     *exitAction;

    QAction     *recentFileActions[MaxRecentFiles];
    QAction     *separatorAction;

    QAction     *undoAction;
    QAction     *redoAction;
    QAction     *cutAction;
    QAction     *copyAction;
    QAction     *pasteAction;
    QAction     *deleteAction;

    QAction     *selectAllAction;
    QAction     *findAction;

    QAction     *fontAction;
    QAction     *colorAction;
    QAction     *backgroundColorAction;

    QAction     *aboutQtAction;
};

#endif // SDIWINDOW_H
