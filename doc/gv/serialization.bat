@set prg_dot="c:\Program Files (x86)\Graphviz\bin\dot.exe"
@%prg_dot% -Tpng serialization_property.gv -o serialization_property.png
@%prg_dot% -Tpng serialization_structure.gv -o serialization_structure.png

pause
