
mkdir _build-msvc_11
cd _build-msvc_11
%prg_cmake% ..   -DCMAKE_CXX_STANDARD=11 -DCMAKE_CXX_STANDARD_REQUIRED=ON
cd ..

mkdir _build-msvc_14
cd _build-msvc_14
%prg_cmake% ..   -DCMAKE_CXX_STANDARD=14 -DCMAKE_CXX_STANDARD_REQUIRED=ON
cd ..

mkdir _build-msvc_17
cd _build-msvc_17
%prg_cmake% ..   -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_STANDARD_REQUIRED=ON
cd ..

mkdir _build-msvc_20
cd _build-msvc_20
%prg_cmake% ..   -DCMAKE_CXX_STANDARD=20 -DCMAKE_CXX_STANDARD_REQUIRED=ON
cd ..



pause
