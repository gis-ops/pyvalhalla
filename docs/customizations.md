## Customize bindings

There's many scenarios where we'd like to deviate from the publicly released bindings package (client needs, internal stuff etc.).

### Procedure

1. Try to contain all the necessary changes to the binding code
2. Create a new branch for this special customization
3. Adapt the `custom_builds.yml` workflow file to build your branch only on push

Then there will a Github artifact which you can download and use to install `pyvalhalla` locally.

### Change Valhalla code

If we can't contain our changes to the binding code for some reason, we create patch files with git, the `./scripts/build_linux.sh` will apply them. On other OSs you'll have to apply the patches before building `upstream`.

```
git -C upstream diff [<filename>] > upstream_patches/your.patch
# need a clean submodule before attempting the build
git -C upstream checkout .
./scripts/build_linux.sh

# if it didn't work, you can apply the patch(es) to continue working on a solution
git -C upstream apply upstream_patches/*
```
