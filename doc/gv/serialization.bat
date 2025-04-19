@set prg_dot="c:\Program Files\Graphviz\bin\dot.exe"
@%prg_dot% -Tpng serialization_property.gv -o serialization_property.png
@%prg_dot% -Tpng serialization_structure.gv -o serialization_structure.png
@%prg_dot% -Tpng void.gv -o void.png
@%prg_dot% -Tpng property.gv -o property.png

pause
