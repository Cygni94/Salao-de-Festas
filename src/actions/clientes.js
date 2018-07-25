export const FETCH_CLIENTES = "FETCH_CLIENTES";
export const CREATE_CLIENTE = "CREATE_CLIENTE";
export const FETCH_CLIENTE = "FETCH_CLIENTE";
export const DELETE_CLIENTE = "DELETE_CLIENTE";

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

export function createCliente(props, cb) {
    const request = fetch(`${ROOT_URL}/`, {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
        },
        props,
    }).then(res => {
        cb();
        return res;
    });

    return {
        type: CREATE_CLIENTE,
        payload: request,
    };
}
