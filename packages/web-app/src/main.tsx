import { initCore, addLayer, setVisible, ndwi } from "./wasmBridge";

(async () => {
  await initCore();
  const id = addLayer();
  setVisible(id, false);

  const nir   = new Float32Array([0.2, 0.7, 0.4]);
  const green = new Float32Array([0.3, 0.6, 0.5]);
  console.log("ndwi:", Array.from(ndwi(nir, green)));
})();
