{
  description = "termkit";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {
        inherit system;
      };

    nativeBuildInputs = [];
    buildInputs = [];

    in {
      formatter = pkgs.alejandra;

      devShells.default = pkgs.mkShell {
        nativeBuildInputs = with pkgs;
          [
            qmk
            just
            minicom
          ]
          ++ nativeBuildInputs
          ++ buildInputs;
      };
    });
}

