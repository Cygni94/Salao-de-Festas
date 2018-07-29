import axios from "axios";

export const FETCH_CLIENTES = "FETCH_CLIENTES";
export const CREATE_CLIENTE = "CREATE_CLIENTE";
export const FETCH_CLIENTE = "FETCH_CLIENTE";
export const DELETE_CLIENTE = "DELETE_CLIENTE";

const ROOT_URL = "http://localhost:3666";

export function fetchClientes(state = {}, action) {
    const request = fetch(`${ROOT_URL}/clientes`).then(function(response) {
        console.log(response.json());
        return response.json();
    });
    return {
        type: FETCH_CLIENTES,
        payload: request,
    };
}

export function createCliente(props, cb) {
    const request = axios.post(`${ROOT_URL}/clientes`, props).then(res => {
        cb();
        return res;
    });

    return {
        type: CREATE_CLIENTE,
        payload: request,
    };
}

export function fetchCliente(id) {
    const request = axios.get(`${ROOT_URL}/clientes/${id}`);

    return {
        type: FETCH_CLIENTE,
        payload: request,
    };
}

export function deleteCliente(id, cb) {
    const request = axios.delete(`${ROOT_URL}/clientes/${id}`).then(res => {
        cb();
        return res;
    });

    return {
        type: DELETE_CLIENTE,
        payload: request,
    };
}
