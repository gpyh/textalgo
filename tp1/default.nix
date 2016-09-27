with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "adt";
  buildInputs = [ stdenv valgrind ];
  shellHook = ''
    export CPATH=$CPATH:$(pwd)/include
    '';
}
