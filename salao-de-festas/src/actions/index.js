export const FETCH_CLIENTES = "FETCH_CLIENTES";

const ROOT_URL =
    "https://my-json-server.typicode.com/coelhojs/salao-de-festas/clientes";

export function fetchClientes(state = {}, action) {
    const request = fetch(`${ROOT_URL}`).then(function(response) {
        return response.json();
    });
    return {
        type: FETCH_CLIENTES,
        payload: request,
    };
}
