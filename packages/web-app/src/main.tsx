import { initCore, dummyAction } from "./wasmBridge";

(async () => {
  await initCore();

  const button = document.querySelector('button');
  button?.addEventListener('click', () => {
    dummyAction();
  });
})();
