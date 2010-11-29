svn log --verbose --xml > my-project.log
C:\Python27\python.exe svn-gource.py --filter-dirs my-project.log > my-project-gource.log
"gource/gource.exe" --log-format custom my-project-gource.log