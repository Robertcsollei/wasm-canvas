// Vite will treat this as an ES module if built with -s EXPORT_ES6=1 and MODULARIZE
// @ts-ignore
import Core from "../../../build/wasm-release/dist/core.js";

let core: any;

const canvas = document.querySelector('canvas')!;
const off = canvas.transferControlToOffscreen();

export async function initCore() {
  core = await Core({
    canvas: off,              // emscripten will bind this to GL
    offscreenCanvas: off,     // (either is fine; canvas is the key)
    noInitialRun: false,      // we want main() to run
  });
  return core;
}

export function dummyAction() {
  core.dummyAction();
}



// export function ndwi(nir: Float32Array, green: Float32Array, out?: Float32Array) {
//   if (!out) out = new Float32Array(nir.length);
//   const bytes = nir.length * 4;

//   // Allocate in Wasm heap
//   const nirPtr = core._malloc(bytes);
//   const greenPtr = core._malloc(bytes);
//   const outPtr = core._malloc(bytes);

//   // Copy into heap
//   core.HEAPF32.set(nir, nirPtr >> 2);
//   core.HEAPF32.set(green, greenPtr >> 2);

//   // Call C++ function
//   core.ndwi(nirPtr, greenPtr, outPtr, nir.length);

//   // Copy back
//   out.set(core.HEAPF32.subarray(outPtr >> 2, (outPtr >> 2) + nir.length));

//   // Free
//   core._free(nirPtr);
//   core._free(greenPtr);
//   core._free(outPtr);
//   return out;
// }
