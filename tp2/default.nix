with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "adt";
  buildInputs = [ stdenv valgrind python3 ];
  shellHook = ''
    export CPATH=$CPATH:$(pwd)/include
  '';
}
