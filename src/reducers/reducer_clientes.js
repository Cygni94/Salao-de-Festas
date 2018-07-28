import _ from "lodash";

import {
    FETCH_CLIENTES,
    FETCH_CLIENTE,
    DELETE_CLIENTE,
    CREATE_CLIENTE,
} from "../actions/clientes";

const INITIAL_STATE = {};

export default function(state = INITIAL_STATE, action) {
    switch (action.type) {
        case FETCH_CLIENTES:
            const newClientes = _.mapKeys(action.payload.clientes, "id");
            return { ...state, ...newClientes };
        case CREATE_CLIENTE:
            return {
                ...state,
                [action.payload.clientes.id]: action.payload.clientes,
            };
        case FETCH_CLIENTE:
            return {
                ...state,
                [action.payload.clientes.id]: action.payload.clientes,
            };
        case DELETE_CLIENTE:
            return _.omit(state, action.payload.clientes.id);
        default:
            return state;
    }
}
